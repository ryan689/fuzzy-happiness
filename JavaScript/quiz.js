//////////////////////////
// CODING CHALLENGE

/*
--- Let's build a fun quiz game in the console! ---

1. Build a function constructor called Question to describe a question. A question should include:
    a) question itself
    b) the answers from which the player can choose the correct one (choose an adequate data structure here, array, object, etc.)
    c) correct answer (I would use a number for this)

2. Create a couple of questions using the constructor

3. Store them all inside an array

4. Select one random question and log it on the console, together with the possible answers (each question should have a number) (Hint: write a method for the Question objects for this task)

5. Use the 'prompt' function to ask the user for the answer. The user should input a number of the correct answer such as you displayed it on Task 4.

6. Check if the answer is correct and print to the console whether the answer is correct or not (Hint: write another method for this).
*/


function shuffle(array) {
    // Fisher-Yates shuffle
    var m = array.length, t, i;

    // While there remain elements to shuffle…
    while (m) {

        // Pick a remaining element…
        i = Math.floor(Math.random() * m--);

        // And swap it with the current element.
        t = array[m];
        array[m] = array[i];
        array[i] = t;
    }

  return array;
}

function Question(question, incorrectAnswers, correctAnswer) {
    this.question = question;
    this.correctAnswer = correctAnswer;
    this.allAnswers = incorrectAnswers;
    this.allAnswers.push(this.correctAnswer);
    
    this.logQuestionToConsole = function() {
        console.log(this.question);
        shuffle(this.allAnswers);
        
        for (var i = 1; i <= this.allAnswers.length; i++) {
            console.log(i + '. ' + this.allAnswers[i - 1]);
        }
        
        this.correctAnswerNum = this.allAnswers.indexOf(correctAnswer) + 1;
    };
    
    this.guessIsCorrect = function(guess) {
        return (guess == this.correctAnswerNum)
    }
}

var questions = [];

questions.push(new Question('What is the best programming language?', ['JavaScript', 'C++', 'PHP'], 'Python'));
questions.push(new Question('What is the square root of 64?', ['5', '7', '9'], '8'));
questions.push(new Question('How long until Lebron James wins another NBA Finals MVP?', ['1 year', '1 month', '6 months', '9 months'], '2 months'));

question = questions[Math.floor(Math.random() * questions.length)];
question.logQuestionToConsole();

var guess = prompt('Which answer number is correct?');
if (question.guessIsCorrect(guess)) {
    console.log('Correct!');
} else {
    console.log('Incorrect.')
}





