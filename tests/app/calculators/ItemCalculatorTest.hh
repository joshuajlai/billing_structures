<?hh // strict

namespace App\Calculators;

use Facebook\HackTest\HackTest;
use function Facebook\FBExpect\expect;

use type App\Calculators\LineItemCalculator;
use type App\Models\{LineItem, LineItemAdjustment, AdjustmentType};

class ItemCalculatorTest extends HackTest
{
  public function testSubtotal_singleAdjustment(): void
  {
    $calculator = new ItemCalculator();
    $lineItem = new LineItem("item");
    $value = 100;
    $lineItem->addLineItemAdjustment(
      new LineItemAdjustment($value, AdjustmentType::Product)
    );
    expect($calculator->subtotal($lineItem))->toBePHPEqual($value);
  }

  public function testSubtotal_dualAdjustment(): void
  {
    $calculator = new ItemCalculator();
    $lineItem = new LineItem("item");
    $lineItem->addLineItemAdjustment(
      new LineItemAdjustment(100, AdjustmentType::Product)
    );
    $lineItem->addLineItemAdjustment(
      new LineItemAdjustment(200, AdjustmentType::Product)
    );
    expect($calculator->subtotal($lineItem))->toBePHPEqual(300);
  }

  public function testSubtotal_taxAdjustmentIncluded(): void
  {
    $calculator = new ItemCalculator();
    $lineItem = new LineItem("item");
    $lineItem->addLineItemAdjustment(
      new LineItemAdjustment(100, AdjustmentType::Product)
    );
    $lineItem->addLineItemAdjustment(
      new LineItemAdjustment(200, AdjustmentType::Product)
    );
    $lineItem->addLineItemAdjustment(
      new LineItemAdjustment(100, AdjustmentType::Tax)
    );
    expect($calculator->subtotal($lineItem))->toBePHPEqual(300);
  }

  public function testSubtotal_discountAdjustmentIncluded(): void
  {
    $calculator = new ItemCalculator();
    $lineItem = new LineItem("item");
    $lineItem->addLineItemAdjustment(
      new LineItemAdjustment(100, AdjustmentType::Product)
    );
    $lineItem->addLineItemAdjustment(
      new LineItemAdjustment(200, AdjustmentType::Product)
    );
    $lineItem->addLineItemAdjustment(
      new LineItemAdjustment(-100, AdjustmentType::Discount)
    );
    expect($calculator->subtotal($lineItem))->toBePHPEqual(200);
  }
}
