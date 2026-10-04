
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00434d92(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  float local_c;
  float local_8;
  
  if (*(short *)(param_1 + 0x8e) != 0) {
    return;
  }
  if (*(short *)(param_1 + 0x84) < 0) {
    return;
  }
  FUN_00407200(&local_18,param_1);
  FUN_0047bd91(&local_14,&local_18,*(undefined4 *)(DAT_006e54d8 + 0x84),0x400);
  if (*(short *)(*(int *)(param_1 + 0x118) + 0x12) == 2) {
    iVar4 = *(int *)(param_1 + 0x110);
    iVar2 = FUN_004a696f();
    if (iVar2 == iVar4) {
      uVar3 = FUN_004a6a46(&local_18,iVar4);
      local_c = _DAT_00666d28 * _DAT_00666cbc;
      local_10 = uVar3;
      cVar1 = FUN_004a694e();
      local_8 = (float)(1 << (cVar1 + 1U & 0x1f));
      FUN_00434e9b(&local_c);
      iVar4 = __ftol();
      FUN_004a6b3a((int)local_10._2_2_,(int)(short)((short)uVar3 - (short)(iVar4 / 2)),param_2);
      FUN_004a6b54(0);
      goto LAB_00434e8a;
    }
  }
  FUN_004a6b19(local_18,local_14,*(undefined4 *)(param_1 + 0x110),1,(char)param_2 == '\0');
  FUN_004a6b54(0);
LAB_00434e8a:
  if ((char)param_2 == '\0') {
    FUN_004a6a39();
  }
  return;
}

