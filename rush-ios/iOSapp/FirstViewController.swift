//
//  FirstViewController.swift
//  iOSapp
//
//  Created by Pierre MARTINEAU on 2/13/16.
//  Copyright © 2016 42. All rights reserved.
//

import UIKit
import MapKit
import CoreLocation

class FirstViewController: UIViewController, MKMapViewDelegate, CLLocationManagerDelegate {
   
    @IBOutlet weak var mapView: MKMapView!
    let locationManager = CLLocationManager()
   
    let regionRadius: CLLocationDistance = 1000
    let initialLocation = CLLocation(latitude: 48.8966838	, longitude: 2.3183755)
    let museumLocation = CLLocation(latitude: 48.8873044, longitude: 2.5912206)
    let churchLocation = CLLocation(latitude: 48.8995279, longitude: 2.3653010)
    let sp3Location = CLLocation(latitude: 48.9354898, longitude: 2.378825300000017)
    var index = Int()
    
    func centerMapOnLocation(location: CLLocation){
        let coordinateRegion = MKCoordinateRegionMakeWithDistance(location.coordinate, regionRadius, regionRadius)
        mapView.setRegion(coordinateRegion, animated: true)
    }
    @IBOutlet weak var segment: UISegmentedControl!
    @IBAction func segmentChanged() {
        switch (segment.selectedSegmentIndex) {
        case 0:
            mapView.mapType = MKMapType.Standard
        case 1:
            mapView.mapType = MKMapType.Satellite
        case 2:
            mapView.mapType = MKMapType.Hybrid
        default:
            break
        }
    }
    
    @IBAction func LocationFinder(sender: UIButton) {
        self.locationManager.delegate = self
        self.locationManager.desiredAccuracy = kCLLocationAccuracyBest
        self.locationManager.requestWhenInUseAuthorization()
        self.locationManager.startUpdatingLocation()
        self.mapView.showsUserLocation = true
        
    }
    
    func mapView(mapView: MKMapView, viewForAnnotation annotation: MKAnnotation) -> MKAnnotationView? {
        
        let identifier = "MyPin"
        
        if annotation.isKindOfClass(MKUserLocation) {
            return nil
        }
        
        let detailButton: UIButton = UIButton(type: UIButtonType.DetailDisclosure)
        
        // Reuse the annotation if possible
        var annotationView = mapView.dequeueReusableAnnotationViewWithIdentifier(identifier)
        
        if annotationView == nil
        {
            annotationView = MKAnnotationView(annotation: annotation, reuseIdentifier: "pin")
            annotationView!.canShowCallout = true
            annotationView!.image = UIImage(named: "custom_pin.png")
            annotationView!.rightCalloutAccessoryView = detailButton
        }
        else
        {
            annotationView!.annotation = annotation
        }
        
        return annotationView
    }
    func locationManager(manager: CLLocationManager, didUpdateLocations locations: [CLLocation])
    {
        let location = locations.last
        let center = CLLocationCoordinate2D(latitude: location!.coordinate.latitude, longitude: location!.coordinate.longitude)
        let region = MKCoordinateRegion(center: center, span: MKCoordinateSpan(latitudeDelta: 0, longitudeDelta: 0))
        self.mapView.setRegion(region, animated: true)
        self.locationManager.stopUpdatingLocation()
    }
    
    func locationManager(manager: CLLocationManager, didFailWithError error: NSError)
    {
        print("Errors: " + error.localizedDescription)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        let school = CLLocationCoordinate2DMake(48.8966838, 2.3183755)
        let schoolPin = MKPointAnnotation()
        schoolPin.coordinate = school
        schoolPin.title = "Ecole 42"
        schoolPin.subtitle = "Cybercafe, Hotel et Cinema"
        mapView.addAnnotation(schoolPin)
        
        let museum = CLLocationCoordinate2DMake(48.8873044, 2.5912206)
        let museumPin = MKPointAnnotation()
        museumPin.coordinate = museum
        museumPin.title = "Cosa Nostra"
        museumPin.subtitle = "skatepark couvert, Chelles"
        mapView.addAnnotation(museumPin)
        
        let church = CLLocationCoordinate2DMake(48.8995279, 2.3653010)
        let churchPin = MKPointAnnotation()
        churchPin.coordinate = church
        churchPin.title = "EPG 18"
        churchPin.subtitle = "skatepark couvert, Paris"
        mapView.addAnnotation(churchPin)
        
        let sp3 = CLLocationCoordinate2DMake(48.9354898, 2.378825300000017)
        let sp3Pin = MKPointAnnotation()
        sp3Pin.coordinate = sp3
        sp3Pin.title = "Square Diderot"
        sp3Pin.subtitle = "streetpark, St denis"
        mapView.addAnnotation(sp3Pin)
        
        centerMapOnLocation(initialLocation)
        
        switch (index) {
        case 1:
            centerMapOnLocation(initialLocation)
        case 2:
            centerMapOnLocation(museumLocation)
        case 3:
            centerMapOnLocation(churchLocation)
        case 4:
            centerMapOnLocation(sp3Location)
        default:
            break
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

