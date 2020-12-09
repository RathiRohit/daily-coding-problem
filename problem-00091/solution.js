import lineReader from 'line-reader';

const instructions = [];
const jmpAndNop = [];

lineReader.eachLine('input.txt', (line, last) => {
    const instruction = line.split(' ');
    instructions.push({
        instruction: instruction[0],
        originalInstruction: instruction[0],
        value: parseInt(instruction[1]),
        isVisited: false
    });
    if (instruction[0] === 'jmp' || instruction[0] === 'nop') {
        jmpAndNop.push(instructions.length - 1);
    }

    if(last){
        jmpAndNop.some(index => {
            if (instructions[index].instruction === 'jmp') {
                instructions[index].instruction = 'nop';
            } else {
                instructions[index].instruction = 'jmp';
            }

            let acc = 0;
            let current = 0;

            while (current < instructions.length) {
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

            if (current >= instructions.length) {
                console.log(acc);
                return true;
            }

            instructions.forEach(instruction => {
                instruction.isVisited = false;
            });

            instructions[index].instruction = instructions[index].originalInstruction;

            return false;
        });
    }
});
