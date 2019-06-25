<?hh // strict

namespace App\Calculators;

use App\Models\Billable;
use App\Models\LineItem;

trait Base implements Calculator
{
  public function total(): int
  {
    return $this->subtotal() + $this->tax();
  }

  public function subtotal(): int
  {
    $billable = $this->getBillable();
    $subtotal = 0;
    $itemCalculator = new ItemCalculator();
    $lineItems = $this->filteredItems();
    foreach($lineItems as $item) {
      $subtotal += $itemCalculator->subtotal($item);
    }

    return $subtotal;
  }

  abstract public function getBillable(): Billable;
  abstract public function tax(): int;
  abstract protected function filteredItems(): vec<LineItem>;
}
