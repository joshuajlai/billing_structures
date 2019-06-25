<?hh // strict

namespace App\Calculators;

use App\Models\Billable;
use App\Models\LineItem;

interface Calculator
{
  public function total(): int;
  public function subtotal(): int;
  public function tax(): int;
}
