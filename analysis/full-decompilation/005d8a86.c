
undefined4 * __thiscall FUN_005d8a86(int param_1,uint param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  puVar2 = (undefined4 *)**(undefined4 **)(param_1 + 0x24);
  uVar3 = 0;
  uVar1 = FUN_0060783f();
  if (uVar1 != 0) {
    do {
      if (uVar3 == param_2) {
        return puVar2 + 2;
      }
      puVar2 = (undefined4 *)*puVar2;
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return (undefined4 *)0x0;
}

