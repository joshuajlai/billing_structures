<?hh // strict

namespace App\Models;

enum LedgerType: string {
  Invoice = 'invoice';
  Payment = 'payment';
}

class Ledger
{
  private int $value;
  private int $referenceId;
  private LedgerType $type;

  public function __construct(int $value, int $referenceId, LedgerType $type)
  {
    $this->value = $value;
    $this->referenceId = $referenceId;
    $this->type = $type;
  }
}
