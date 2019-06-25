<?hh // strict

namespace App\Controllers\Payment;

use App\Models\{Payment, Transaction, Ledger, LedgerType};

class ExecutePayment
{
  public function call(Payment $payment): Payment
  {
    foreach ($payment->getTransactions() as $transaction)
    {
      if ($transaction->isCompleted()) {
        continue;
      }
      $this->processTransaction($transaction);
      if ($transaction->isCompleted()) {
        /**
         * Note: This feels weird to set the transaction id as the reference but the
         * ledger type is payment. Ideally, the ledger always points to the thing that
         * resulted in currency exchanging parties.
         */
        $ledger = new Ledger(
          $transaction->getAmount(),
          $transaction->getId(),
          LedgerType::Payment
        );
      }
    }

    return $payment;
  }

  private function processTransaction(Transaction $transaction): void
  {
    // depending on transaction type, initiate service wrapper and execute.
    // generating TransactionLog's would go here.
  }
}
