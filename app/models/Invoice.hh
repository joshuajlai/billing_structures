<?hh // strict

namespace App\Models;

enum InvoiceStatus: string {
  Pending = 'pending';
  Finalized = 'finalized';
  Canceled = 'canceled';
}

class Invoice extends Billable
{
  private int $id;
  private InvoiceStatus $status;

  public function __construct()
  {
    $this->id = \rand(0, 1000000);
    $this->status = InvoiceStatus::Pending;
  }

  public function getId(): int
  {
    return $this->id;
  }

  public function finalize(): void
  {
    $this->status = InvoiceStatus::Finalized;
  }

  public function isFinalized(): bool
  {
    return $this->status == InvoiceStatus::Finalized;
  }

  public function cancel(): void
  {
    $this->status = InvoiceStatus::Canceled;
  }
}
