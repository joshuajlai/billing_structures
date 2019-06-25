<?hh // strict

namespace App\Calculators;

use HH\Lib\{C, Vec};

use App\Models\{LineItem, LineItemAdjustment, AdjustmentType};

class ItemCalculator
{
  public function subtotal(LineItem $item): int
  {
    $validTypes = vec[AdjustmentType::Product, AdjustmentType::Discount];
    return $this->calculateSum($item, $validTypes);
  }

  public function tax(LineItem $item): int
  {
    $validTypes = vec[AdjustmentType::Tax];
    return $this->calculateSum($item, $validTypes);
  }

  protected function calculateSum(
    LineItem $item,
    vec<AdjustmentType> $validTypes
  ): int {

    $sum = 0;
    $adjustments = $this->filteredAdjustments($item->getLineItemAdjustments(), $validTypes);
    foreach ($adjustments as $adjustment) {
      $sum += $adjustment->getValue();
    }

    return $sum;
  }

  protected function filteredAdjustments(
    vec<LineItemAdjustment> $adjustments,
    vec<AdjustmentType> $validTypes
  ): vec<LineItemAdjustment> {
    return Vec\filter(
      $adjustments,
      $adjustment ==> {
        return null !== C\find(
          $validTypes,
          $validType ==> $validType == $adjustment->getType()
        );
      }
    );
  }
}
