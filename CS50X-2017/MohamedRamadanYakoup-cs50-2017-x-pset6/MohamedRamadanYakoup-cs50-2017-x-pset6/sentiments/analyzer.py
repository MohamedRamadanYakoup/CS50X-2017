import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""

        # TODO
        self.wordp = set()
        self.wordn = set()
        positive = open(positives, "r")
        negative = open(negatives, "r")
        for line1 in positive:
            if not line1.startswith(";"):
                self.wordp.add(line1.strip("\n"))
        for line2 in negative:
            if not line2.startswith(";"):
                self.wordn.add(line2.strip("\n"))
        positive.close()
        negative.close()

    def analyze(self, tweet):
        """Analyze text for sentiment, returning its score."""

        # TODO
        score = 0
        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(tweet)
        for i in tokens:
            if i.lower() in self.wordp:
                score += 1
            elif i.lower() in self.wordn:
                score -= 1
            else:
                score += 0
            return score
