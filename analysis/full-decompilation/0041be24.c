
undefined4 FUN_0041be24(undefined4 param_1,short param_2)

{
  undefined4 uVar1;
  undefined2 uVar2;
  short sVar3;
  int local_14 [2];
  int local_c [2];
  
  sVar3 = param_2;
  _param_2 = param_1;
  FUN_00575b11(local_14,&param_2);
  uVar2 = 0;
  if (local_14[0] != 0) {
    uVar1 = FUN_00580a92(local_c);
    while (uVar2 = (undefined2)((uint)uVar1 >> 0x10), local_c[0] != 0) {
      if (sVar3 < *(short *)(local_c[0] + 7)) {
        sVar3 = *(short *)(local_c[0] + 7);
      }
      uVar1 = FUN_0041ddb4();
    }
  }
  return CONCAT22(uVar2,sVar3);
}

