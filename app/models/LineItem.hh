<?hh // strict

namespace App\Models;

use HH\Lib\Vec;

class LineItem
{
  private vec<LineItemAdjustment> $lineItemAdjustments;
  private string $name;

  public function __construct(string $name)
  {
    $this->lineItemAdjustments = vec[];
    $this->name = $name;
  }

  public function getName(): string
  {
    return $this->name;
  }

  public function getLineItemAdjustments(): vec<LineItemAdjustment>
  {
    return $this->lineItemAdjustments;
  }

  public function addLineItemAdjustment(LineItemAdjustment $adjustment): void
  {
    $this->lineItemAdjustments[] = $adjustment;
  }

  public function removeLineItemAdjustment(LineItemAdjustment $adjustment): void
  {
    $this->lineItemAdjustments = Vec\diff_by(
      $this->lineItemAdjustments,
      vec[$adjustment],
      $item ==> $item->getId()
    );
  }
}
