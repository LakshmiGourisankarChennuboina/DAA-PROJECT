# PharmaFEFO – Pharmacy Inventory Management System

FEFO (First Expired, First Out) pharmacy inventory prototype built on a **Min Heap** keyed by expiry date.

## Features
- Dashboard with stats, stock-distribution pie chart, quantity bar chart, and expiry alerts
- Add medicine batches (DD-MM-YYYY dates, duplicate-ID checks)
- Inventory in FEFO order, with search and status filters
- FEFO dispensing and partial dispensing (batch removed at zero)
- Purge expired batches into an expired stock log
- Data structure comparison (Min Heap vs Sorted List vs Unsorted List)
- Min Heap visualizer with Heapify-Up / Heapify-Down traces
- Data stored in browser localStorage; sample data and reset included

## Running
Open `index.html` in a modern browser. It loads React, Babel, and Tailwind from CDNs, so an internet connection is required.

## Note
This is a standalone frontend prototype. It is not connected to any C program or text files.
