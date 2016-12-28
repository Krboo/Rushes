//
//  CelluleTableViewCell.swift
//  iOSapp
//
//  Created by Pierre MARTINEAU on 2/13/16.
//  Copyright © 2016 42. All rights reserved.
//

import UIKit

class CelluleTableViewCell: UITableViewCell {
    
    @IBOutlet weak var nameLabel: UILabel!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
