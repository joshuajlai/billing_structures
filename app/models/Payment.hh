<?hh // strict

namespace App\Models;

class Payment extends Billable
{
  /**
   * Restrict each payment attempt to a single invoice so that you cannot attempt
   * payment across invoices leading to more complicated reconciliation logic.
   */
  private int $invoiceId;

  /**
   * Allow for multiple transactions since a transaction can only have 1 payment source.
   * This allows for usage of multiple payment sources per payment attempt such as
   * CC, giftcard, giftcard.
   */
  private vec<Transaction> $transactions;

  public function __construct(int $invoiceId)
  {
    $this->invoiceId = $invoiceId;
    $this->transactions = vec[];
  }

  /**
   * A payment's status is contigent on the transactions' statuses. Instead of trying
   * to have 2 levels of status, just derive it at runtime. If this is needed in the DB
   * for datamining/business intelligence, change to a column that's updated whenever
   * transaction status are calculated.
   */
  public function status(): TransactionStatus
  {
    $statusBuckets = dict[
      TransactionStatus::Pending => 0,
      TransactionStatus::Processing => 0,
      TransactionStatus::Completed => 0
    ];
    foreach ($this->transactions as $transaction) {
      $statusBuckets[$transaction->getStatus()] += 1;
    }

    if ($statusBuckets[TransactionStatus::Processing] > 0) {
      return TransactionStatus::Processing;
    } elseif ($statusBuckets[TransactionStatus::Pending] > 0) {
      return TransactionStatus::Pending;
    } elseif ($statusBuckets[TransactionStatus::Completed] > 0) {
      return TransactionStatus::Completed;
    }

    // if someone forgot to update this to include a new status, default to pending
    return TransactionStatus::Pending;
  }

  public function addTransaction(Transaction $transaction): void
  {
    $this->transactions[] = $transaction;
  }

  public function getTransactions(): vec<Transaction>
  {
    return $this->transactions;
  }
}
