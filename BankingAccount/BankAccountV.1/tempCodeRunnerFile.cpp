vector<Account> bank_accounts;
    bank_accounts.push_back(Account{});
    bank_accounts.push_back(Account{"Moe", 2000});
    bank_accounts.push_back(Account{"Curly", 5000});

    display(bank_accounts);
    deposit(bank_accounts, 1000);
    withdraw(bank_accounts, 2000);

    vector<Saving_Account> save_accounts;
    save_accounts.push_back(Saving_Account{});
    save_accounts.push_back(Saving_Account{"superman", 1000, 0.05});
    save_accounts.push_back(Saving_Account{"wolverine", 5000, 0.6});
    save_accounts.push_back(Saving_Account{"spiderman", 2000, 0.05});

    display(save_accounts);
    deposit(save_accounts, 1000);
    withdraw(save_accounts, 2000);

    vector<Checking_Account> check_accounts;
    check_accounts.push_back(Checking_Account{});
    check_accounts.push_back(Checking_Account{"Ironman", 1000});
    check_accounts.push_back(Checking_Account{"thanos", 5000, 5});
    check_accounts.push_back(Checking_Account{"batman", 2000});
    
    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);