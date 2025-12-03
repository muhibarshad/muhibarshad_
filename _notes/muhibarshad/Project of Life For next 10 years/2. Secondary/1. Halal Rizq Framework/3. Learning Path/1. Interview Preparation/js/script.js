navigator.geolocation.getCurrentPosition(
  function (pos) {
    console.log(pos);
    const { latitude } = pos.coords;
    const { longitude } = pos.coords;
    console.log(`https://www.google.com/maps/@${latitude},${longitude}`)
  },
  function () {
    alert("Does not work because of not allowing to your location.");
  }
);