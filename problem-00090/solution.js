import lineReader from 'line-reader';

const instructions = [];

lineReader.eachLine('input.txt', (line, last) => {
    const instruction = line.split(' ');
    instructions.push({
        instruction: instruction[0],
        value: parseInt(instruction[1]),
        isVisited: false
    });

    if(last){
        let acc = 0;
        let current = 0;
        while (true) {
            if (instructions[current].isVisited) {
                break;
            }
            instructions[current].isVisited = true;

            switch (instructions[current].instruction) {
                case 'nop':
                    current++;
                    break;
                case 'acc':
                    acc += instructions[current].value;
                    current++;
                    break;
                case 'jmp':
                    current += instructions[current].value;
                    break;
            }
        }

        console.log(acc);
    }
});
