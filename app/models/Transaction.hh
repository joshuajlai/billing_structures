<?hh // strict

namespace App\Models;

enum TransactionStatus: string {
  Pending = 'pending';
  Processing = 'processing';
  Completed = 'completed';
}

/**
 * Abstract representation of transaction attempt such as a Credit Card transaction or
 * ACH transaction
 */
class Transaction
{
  private PaymentSource $paymentSource;
  private int $amount;
  private TransactionStatus $status;
  private vec<TransactionLog> $transactionLogs;

  public function __construct(PaymentSource $paymentSource, int $amount)
  {
    $this->paymentSource = $paymentSource;
    $this->transactionLogs = vec[];
    $this->status = TransactionStatus::Pending;
    $this->amount = $amount;
  }

  public function addLog(TransactionLog $transactionLog): void
  {
    $this->transactionLogs[] = $transactionLog;
  }

  public function getStatus(): TransactionStatus
  {
    return $this->status;
  }
}
