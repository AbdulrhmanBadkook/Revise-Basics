#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;

class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1 ,AddNewMode=2};
    enMode _Mode;


    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkToDelete = false;
    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

    }

    static string _ConvertClientObjecttoLine(clsBankClient data, string Seperator = "#//#") {
        string stClientRecord = "";
        stClientRecord += data.FirstName + Seperator;
        stClientRecord += data.LastName + Seperator;
        stClientRecord += data.Email + Seperator;
        stClientRecord += data.Phone + Seperator;
        stClientRecord += data.AccountNumber() + Seperator;
        stClientRecord += data.PinCode + Seperator;
        stClientRecord += to_string(data.AccountBalance);

        return stClientRecord;
    }
    struct stTrnsferLogRecord;
    static stTrnsferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
    {
        stTrnsferLogRecord TrnsferLogRecord;

        vector <string> vTrnsferLogRecordLine = clsString::Split(Line, Seperator);
        TrnsferLogRecord.DateTime = vTrnsferLogRecordLine[0];
        TrnsferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
        TrnsferLogRecord.DestinationAccountNumber = vTrnsferLogRecordLine[2];
        TrnsferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
        TrnsferLogRecord.srcBalanceAfter = stod(vTrnsferLogRecordLine[4]);
        TrnsferLogRecord.destBalanceAfter = stod(vTrnsferLogRecordLine[5]);
        TrnsferLogRecord.UserName = vTrnsferLogRecordLine[6];

        return TrnsferLogRecord;

    }
    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }


   static vector <clsBankClient> _LoadCleintsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string line;
            while (getline(MyFile, line))
            {
                clsBankClient client = _ConvertLinetoClientObject(line);
                vClients.push_back(client);
            }
            MyFile.close();
        }
        return vClients;
    }
   void _SaveClientDataToFile(vector <clsBankClient> client){
       fstream save;
       
       save.open("Clients.txt", ios::out);//overwrite mode (save)
       if (save.is_open())
       {
           string line;
           for (clsBankClient c :client)
           {
               if (c.MarkedForDeleted() != true)
               {
                   line = _ConvertClientObjecttoLine(c);
                   save << line << endl;
               }
               
           }

               
           save.close();
       }
     
   
   
   }

   void _update() {

       vector <clsBankClient> c_data;
       c_data = _LoadCleintsDataFromFile();
       //now I have the data here in this method 
       for (clsBankClient &data :c_data)
       {
           if (AccountNumber()==data.AccountNumber())//each data = object 
           {
               
               data = *this;//contains the updated recorde 
               break;
           }
       }
       _SaveClientDataToFile(c_data);

   }

   void _AddNew() {

       _AddDataLineToFile(_ConvertClientObjecttoLine(*this));

   }
   void _AddDataLineToFile(string  stDataLine)
   {
       fstream MyFile;
       MyFile.open("Clients.txt", ios::out | ios::app);

       if (MyFile.is_open())
       {

           MyFile << stDataLine << endl;

           MyFile.close();
       }

   }
   string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient,
       string UserName, string Seperator = "#//#")
   {
       string TransferLogRecord = "";
       TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
       TransferLogRecord += AccountNumber() + Seperator;
       TransferLogRecord += DestinationClient.AccountNumber() + Seperator;
       TransferLogRecord += to_string(Amount) + Seperator;
       TransferLogRecord += to_string(AccountBalance) + Seperator;
       TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
       TransferLogRecord += UserName;
       return TransferLogRecord;
   }

   void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
   {

       string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

       fstream MyFile;
       MyFile.open("TransferLog.txt", ios::out | ios::app);

       if (MyFile.is_open())
       {

           MyFile << stDataLine << endl;

           MyFile.close();
       }

   }
   
public:
    struct stTrnsferLogRecord
    {
        string DateTime;
        string SourceAccountNumber;
        string DestinationAccountNumber;
        float Amount;
        float srcBalanceAfter;
        float destBalanceAfter;
        string UserName;

    };
    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkToDelete;
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }
    void deposit(int read) {
        _AccountBalance += read;
        save();

    }
    void Withdraw(int read) {
        _AccountBalance -= read;
        save();

    }
    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }
   
    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    void Print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << FirstName;
        cout << "\nLastName    : " << LastName;
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << Email;
        cout << "\nPhone       : " << Phone;
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";

    }
  

    static clsBankClient Find(string AccountNumber) {

        vector <clsBankClient> vclients;
        fstream file;
        file.open("Clients.txt", ios::in);//read mode
        if (file.is_open())
        {
            string line;
            while (getline(file,line))
            {
                clsBankClient client = _ConvertLinetoClientObject(line);
                if (client.AccountNumber() == AccountNumber)
                {
                    file.close();
                    return client;
                }
                vclients.push_back(client);
            }
            file.close();
        }//if client not found 
        return  _GetEmptyClientObject();
    }
   static  vector<clsBankClient> GetClientList() {
        vector<clsBankClient>clientData=clsBankClient::_LoadCleintsDataFromFile();
        return clientData;
    }
    static clsBankClient Find(string AccountNumber,string PinCode1) {
    
        vector <clsBankClient> vclient;
        fstream file;
        file.open("Clients.txt", ios::in);//read only
        if (file.is_open())
        {
            string line;
            while (getline(file,line))
            {
                clsBankClient client = _ConvertLinetoClientObject(line);
                if (client.AccountNumber() == AccountNumber && client.GetPinCode() == PinCode1)
                {
                    file.close();
                    return client;
                }
                vclient.push_back(client);
            }
            file.close();
        }
        return _GetEmptyClientObject();
    }
    static bool IsClientExist(string AccountNumber){
    
        clsBankClient client1 = clsBankClient::Find(AccountNumber);
        return (!client1.IsEmpty());
    }

    enum ensave_result{svFaildEmptyObject=0,svSucceeded=1,svFaildAccountInUse=2 };

    ensave_result save() {

        switch (_Mode)
        {

        case enMode::EmptyMode:
        {
            return svFaildEmptyObject;
        }
        case enMode::UpdateMode: {

            _update();
            return svSucceeded;
        }
        case enMode::AddNewMode: {
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return svFaildAccountInUse;
            }
            else
            {
                _AddNew();
                //add new code here 
                 _Mode = enMode::UpdateMode;
                return svSucceeded;
            }
            break;
            
        }
       
        default:
            break;
        }



    }
    static clsBankClient GetAddNewClientObject(string AccountNumber){
    

        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    bool Deleteclient() {
        vector <clsBankClient> c_data;
        c_data = _LoadCleintsDataFromFile();
        for (clsBankClient& c : c_data)
        {
            if (c.AccountNumber() == _AccountNumber)
            {
                
                c._MarkToDelete = true;
                break;
            }

        }
        
        *this = _GetEmptyClientObject();
        _SaveClientDataToFile(c_data);
        return true;
    }

    static float sumBalances() {
        vector <clsBankClient> data = _LoadCleintsDataFromFile();
        float balance_sum = 0;
        for (clsBankClient &m:data)
        {
            balance_sum += m.AccountBalance;
        }


        return balance_sum;
    }
    bool Transfer(float Amount, clsBankClient& DestinationClient, string UserName)
    {
        if (Amount > AccountBalance)
        {
            return false;
        }

        Withdraw(Amount);
        DestinationClient.deposit(Amount);
        _RegisterTransferLog(Amount, DestinationClient, UserName);
        return true;
    }


    static  vector <stTrnsferLogRecord> GetTransfersLogList()
    {
        vector <stTrnsferLogRecord> vTransferLogRecord;

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

            stTrnsferLogRecord TransferRecord;

            while (getline(MyFile, Line))
            {

                TransferRecord = _ConvertTransferLogLineToRecord(Line);

                vTransferLogRecord.push_back(TransferRecord);

            }

            MyFile.close();

        }

        return vTransferLogRecord;

    }






};

