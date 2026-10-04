
void FUN_00465b21(int param_1,undefined4 param_2,undefined4 param_3,short param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((DAT_006e537c & 1) == 0) {
    DAT_006e537c = DAT_006e537c | 1;
    FUN_00403288();
    FUN_00635543(&LAB_00465b9b);
  }
  FUN_00470383(param_2,param_3,0);
  *(undefined2 *)(param_1 + 8) = 0;
  **(undefined1 **)(param_1 + 4) = 0;
  if (0 < param_4) {
    iVar1 = FUN_0046fbe5(0xffffffff);
    if (param_4 <= iVar1) {
      uVar3 = 0xffffffff;
      uVar2 = FUN_004705f2((int)param_4,0xffffffff);
      FUN_0046f847(uVar2,uVar3);
    }
  }
  return;
}

