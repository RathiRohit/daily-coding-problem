import lineReader from 'line-reader';

const allergensMap = {};
const ingredientMap = {};
const ingredientCount = {};

function intersection(arrOfArr) {
    const intersection = [];
    const head = arrOfArr[0];
    arrOfArr = [...arrOfArr].slice(1);
    head.forEach(item => {
        if (arrOfArr.every(items => items.includes(item))) {
            intersection.push(item);
        }
    });
    return intersection;
}

lineReader.eachLine('input.txt', (line, last) => {
    const tokens = line.split(' ');
    if (tokens[tokens.length - 1].includes('(')) {
        const ingredients = tokens.slice(0, -1);
        ingredients.forEach(ingredient => {
            if (!ingredientCount[ingredient]) {
                ingredientCount[ingredient] = 0;
            }
            ingredientCount[ingredient]++;
        });

        const allergens = tokens[tokens.length - 1].slice(1,-1).split(',');
        allergens.forEach(allergen => {
            if (!allergensMap[allergen]) {
                allergensMap[allergen] = [];
            }
            allergensMap[allergen].push([...ingredients]);
        });
    }

    if (last) {
        while (Object.keys(allergensMap).length !== 0) {
            Object.keys(allergensMap).forEach(allergen => {
                const commonIngredients = intersection(allergensMap[allergen]);
                const newCommonIngredients = [];

                commonIngredients.forEach(ingredient => {
                    if (!ingredientMap[ingredient]) {
                        newCommonIngredients.push(ingredient);
                    }
                });

                if (newCommonIngredients.length === 1) {
                    ingredientMap[newCommonIngredients[0]] = allergen;
                    delete allergensMap[allergen];
                }
            });
        }

        let dangerousIngredients = [];
        Object.keys(ingredientMap).forEach(ingredient => {
            dangerousIngredients.push({
                ingredient,
                allergen: ingredientMap[ingredient]
            });
        });
        dangerousIngredients = dangerousIngredients.sort((a, b) => {
            return a.allergen.localeCompare(b.allergen);
        });

        let dangerousIngredientsList = dangerousIngredients[0].ingredient;
        for (let i=1; i<dangerousIngredients.length; i++) {
            dangerousIngredientsList += `,${dangerousIngredients[i].ingredient}`;
        }
        console.log(dangerousIngredientsList);
    }
});
