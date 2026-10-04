
uint __fastcall FUN_0050c626(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  float10 fVar5;
  undefined1 local_20 [12];
  undefined1 local_14 [12];
  float local_8;
  
  fVar5 = (float10)FUN_00473496(DAT_006e5490);
  local_8 = (float)fVar5;
  uVar1 = FUN_0049b86e(local_20,&local_8,param_1 + 0x18);
  FUN_0045ef64(local_14,param_1,uVar1);
  iVar2 = __ftol();
  uVar3 = __ftol();
  uVar4 = __ftol();
  return uVar4 | (iVar2 << 8 | uVar3) << 8;
}

