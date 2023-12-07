from collections import defaultdict
from tkinter import Tk, Entry, Label, Toplevel
from tkinter.simpledialog import askstring
from os.path import isfile
from json import load, dump
from time import time
from enchant import Dict


class Game:
    """
    Represents a word game.

    Args:
        master: The Tkinter root window.

    Attributes:
        dictionary: The dictionary object for word validation.
        scores: A dictionary to store player scores.
        word_length: The length of the word to be entered.
        time_limit: The time limit for each round.
        score: The player's current score.
        start_time: The start time of the game.
        used_words: A set of words already used.
        entry: The Tkinter Entry widget for word input.
        label: The Tkinter Label widget for displaying game information.
    """

    def __init__(self, master: Tk) -> None:
        self.dictionary = Dict("en_US")
        self.scores = load(open('scores.json', 'r')) if isfile('scores.json') else defaultdict(int)

        self.master: Tk = master
        self.word_length: int = 3
        self.time_limit: int = 5
        self.score: int = 0
        self.start_time: float = time()
        self.used_words: set[str] = set()
        self.entry: Entry = Entry(master)
        self.entry.pack()

        self.label = Label(master, text="")
        self.label.pack()

        self.master.after(1000, self.update)

    def update(self) -> None:
        if self.word_length != 73:
            if self.is_time_up():
                self.end_game()
                return
            self.check_and_update_word()
        self.master.after(1000, self.update)

    def is_time_up(self) -> bool:
        return time() - self.start_time > self.time_limit

    def end_game(self) -> None:
        self.label.config(text="Time's up. Game Over.")
        player_name = askstring("Input", "Enter your name:")
        self.save_score(player_name, self.score)
        self.show_leaderboard()

    def check_and_update_word(self) -> None:
        word = self.entry.get()
        if len(word) >= self.word_length and self.dictionary.check(word) and word not in self.used_words:
            self.level_up()

    def level_up(self) -> None:
        self.score += 10
        self.word_length += 1
        self.time_limit += 2
        self.entry.delete(0, 'end')
        self.start_time = time()
        self.label.config(text=f"Enter a word of length {self.word_length} in {self.time_limit} seconds. Score: {self.score}")

    def save_score(self, name: str | None, score: int) -> None:
        self.scores[name] = score
        with open('scores.json', 'w') as f:
            dump(self.scores, f)

    def show_leaderboard(self) -> None:
        leaderboard_window = Toplevel(self.master)
        leaderboard_window.title("Leaderboard")
        sorted_scores: list[tuple[str | None, int]] = sorted(
            [(name, score) for name, score in self.scores.items() if score > 0], key=lambda x: x[1], reverse=True)
        for i, (name, score) in enumerate(sorted_scores):
            Label(leaderboard_window, text=f"{name}: {score}").grid(row=i)


root: Tk = Tk()
root.geometry("800x600")
game = Game(root)
root.mainloop()
