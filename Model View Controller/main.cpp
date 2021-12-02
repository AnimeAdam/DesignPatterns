//It's the god damn model view controller pattern.

//Below example is in a different language but it's easy to understand.
const model = {
    currentCar: null,
    cars : [
        {
            clickCount: 0,
            name : 'Coupe Maserati',
            imgSrc : 'img/black-convertible-coupe.jpg',
        },
        {
            clickCount: 0,
            name : 'Camaro SS 1LE',
            imgSrc : 'img/chevrolet-camaro.jpg',
        },
        {
            clickCount: 0,
            name : 'Dodger Charger 1970',
            imgSrc : 'img/dodge-charger.jpg',
        },
        {
            clickCount: 0,
            name : 'Ford Mustang 1966',
            imgSrc : 'img/ford-mustang.jpg',
        },
        {
            clickCount: 0,
            name : '190 SL Roadster 1962',
            imgSrc : 'img/mercedes-benz.jpg',
        },
    ],
};

const carListView = {
    init() {
    // store the DOM element for easy access later
    this.carListElem = document.getElementById('car-list');

    // render this view (update the DOM elements with the right values)
    this.render();
},

render() {
    let car;
    let elem;
    let i;
    // get the cars to be render from the controller
    const cars = controller.getCars();

    // to make sure the list is empty before rendering
    this.carListElem.innerHTML = '';

    // loop over the cars array
    for (let i = 0; i < cars.length; i++) {
        // this is the car we've currently looping over
        car = cars[i];

        // make a new car list item and set its text
        elem = document.createElement('li');
        elem.className = 'list-group-item d-flex justify-content-between lh-condensed';
        elem.style.cursor = 'pointer';
        elem.textContent = car.name;
        elem.addEventListener(
            'click',
            (function(carCopy) {
                return function() {
                    controller.setCurrentCar(carCopy);
                    carView.render();
                };
            })(car)
        );
        // finally, add the element to the list
        this.carListElem.appendChild(elem);
    }
},
};

const carView = {
    init() {
    // store pointers to the DOM elements for easy access later
    this.carElem = document.getElementById('car');
    this.carNameElem = document.getElementById('car-name');
    this.carImageElem = document.getElementById('car-img');
    this.countElem = document.getElementById('car-count');
    this.elCount = document.getElementById('elCount');


    // on click, increment the current car's counter
    this.carImageElem.addEventListener('click', this.handleClick);

    // render this view (update the DOM elements with the right values)
    this.render();
},

handleClick() {
    return controller.incrementCounter();
},

render() {
    // update the DOM elements with values from the current car
    const currentCar = controller.getCurrentCar();
    this.countElem.textContent = currentCar.clickCount;
    this.carNameElem.textContent = currentCar.name;
    this.carImageElem.src = currentCar.imgSrc;
    this.carImageElem.style.cursor = 'pointer';
},
};


const controller = {
    init() {
    // set the current car to the first one in the list
    model.currentCar = model.cars[0];

    // tell the views to initialize
    carListView.init();
    carView.init();
},

getCurrentCar() {
    return model.currentCar;
},

getCars() {
    return model.cars;
},

// set the currently selected car to the object that's passed in
setCurrentCar(car) {
    model.currentCar = car;
},

// increment the counter for the currently-selected car
incrementCounter() {
    model.currentCar.clickCount++;
    carView.render();
},
};

// Let's goooo!
controller.init();