
int __fastcall FUN_0041d667(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_54;
  int local_50;
  byte local_4a;
  void *local_8;
  
  local_8 = operator_new(0xc800);
  if (local_8 == (void *)0x0) {
    iVar1 = -200;
  }
  else {
    iVar3 = 0;
    iVar1 = 0x40;
    while (iVar2 = FUN_0041a545(&local_54,iVar1), iVar2 == 0) {
      if (((local_4a & 4) == 0) && (local_54 != 0x72736d70)) {
        iVar2 = FUN_0041a615(iVar1,iVar3,local_50,local_8);
        if (iVar2 != 0) {
          return iVar2;
        }
        FUN_0041b869(iVar1,iVar3);
      }
      else {
        iVar3 = iVar3 + local_50;
      }
      iVar1 = iVar1 + local_50;
    }
    FUN_006321f0(local_8);
    FUN_00412fe1(iVar1 - iVar3);
    *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x14) = 0;
    iVar1 = 0;
  }
  return iVar1;
}

