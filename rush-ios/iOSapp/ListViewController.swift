//
//  ListViewController.swift
//  iOSapp
//
//  Created by Pierre MARTINEAU on 2/13/16.
//  Copyright © 2016 42. All rights reserved.
//

import UIKit

class ListViewController: UIViewController, UITableViewDataSource, UITableViewDelegate {
    
    @IBOutlet weak var myTableView: UITableView! {
        didSet {
            myTableView.dataSource = self
            myTableView.delegate = self
        }
    }
    var list = [String]()
    var newCell: String = ""
    
    override func viewDidLoad() {
        super.viewDidLoad()

        list = ["Ecole 42", "Cosa Nostra", "EPG 18", "Square Diderot"]
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    func numberOfSectionsInTableView(tableView: UITableView) -> Int {
        return 1
    }
    
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return list.count
    }
    
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCellWithIdentifier("CustomCell", forIndexPath: indexPath) as! CelluleTableViewCell
        cell.nameLabel.text = list[indexPath.row]
        return cell
    }
    
    func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
        self.performSegueWithIdentifier("linkShow", sender: indexPath.row)
    }
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        if segue.identifier == "linkShow" {
            if let destination = segue.destinationViewController as? FirstViewController {
                destination.index = sender as! Int + 1
            }
        }
    }
}
