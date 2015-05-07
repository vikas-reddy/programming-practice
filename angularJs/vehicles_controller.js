function vehiclesController($scope) {
  $scope.vehicles = [
  {name: 'car', price: '8'},
  {name: 'bike', price: '1'},
  {name: 'bus', price: '30'}
  ];

  $scope.add = function() {
    if($scope.vehicle === undefined) {
      alert('No details entered');
      return;
    }
    // Cloning the vehicle
    var vehicle = {
      name: $scope.vehicle.name,
      price: $scope.vehicle.price
    }
    $scope.vehicles.push(vehicle);
  }

  $scope.remove = function(index) {
    $scope.vehicles.splice(index, 1);
  }
}

