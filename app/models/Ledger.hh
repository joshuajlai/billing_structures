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
    $this->referenceId = $referenceId;
    $this->type = $type;
    $this->value = $this->processValue($value, $type);
  }

  private function processValue(int $value, LedgerType $type): int
  {
    if ($type == LedgerType::Payment) {
      $value = $value * -1;
    }

    return $value;
  }
}
