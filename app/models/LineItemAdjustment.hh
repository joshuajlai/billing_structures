<?hh // strict

namespace App\Models;

enum AdjustmentType: string {
  Product = 'product';
  Tax = 'tax';
  Discount = 'discount';
}

class LineItemAdjustment
{
  private int $id;
  private int $value;
  private AdjustmentType $type;

  public function __construct(int $value, AdjustmentType $type)
  {
    $this->verifyValue($value, $type);
    $this->value = $value;
    $this->type = $type;
    $this->id = \rand(0, 10000000000);
  }

  public function getId(): int
  {
    return $this->id;
  }

  public function getValue(): int
  {
    return $this->value;
  }

  public function getType(): AdjustmentType
  {
    return $this->type;
  }

  public function delete(): void
  {
  }

  private function verifyValue(int $value, AdjustmentType $type): void
  {
    switch($type) {
    case AdjustmentType::Product:
      if ($value < 0) {
        throw new \Exception("Invalid value for type {$type}");
      }
      break;
    case AdjustmentType::Tax:
      if ($value < 0) {
        throw new \Exception("Invalid value for type {$type}");
      }
      break;
    case AdjustmentType::Discount:
      if ($value >= 0) {
        throw new \Exception("Invalid value for type {$type}");
      }
      break;
    }
  }
}
