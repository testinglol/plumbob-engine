
void FUN_00429c3b(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = FUN_00465062(param_2);
  if (iVar1 == 0) {
    FUN_00465090(param_4);
  }
  else {
    FUN_004650d0(param_4,iVar1);
    iVar3 = 0;
    if (0 < iVar1) {
      do {
        uVar2 = FUN_0046518a(param_2,iVar3);
        FUN_004651b1(param_4,iVar3,uVar2);
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar1);
    }
  }
  return;
}

