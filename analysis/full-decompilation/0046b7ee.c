
undefined4 FUN_0046b7ee(void)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  uVar2 = FUN_00406714();
  sVar1 = FUN_004066d0();
  while (sVar1 != 0) {
    puVar3 = (undefined4 *)FUN_004066e7(0);
    FUN_00406675(puVar3);
    if (puVar3 != (undefined4 *)0x0) {
      (**(code **)*puVar3)(1);
    }
    sVar1 = FUN_004066d0();
  }
  return uVar2;
}

