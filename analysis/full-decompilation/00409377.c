
undefined4 __thiscall FUN_00409377(int *param_1,int param_2,int param_3)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  
  if (*param_1 != 0) {
    return 0;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  iVar1 = FUN_004580cc(0);
  pcVar3 = &DAT_006de560;
  param_1[2] = iVar1;
  pcVar2 = (char *)FUN_004705f2(2,0xffffffff);
  iVar1 = _strcmp(pcVar2,pcVar3);
  if (((iVar1 == 0) || (iVar1 = FUN_0040cd0e(), iVar1 < 0)) || (1 < iVar1)) goto LAB_004094e1;
  iVar1 = FUN_0040cc3f();
  pcVar2 = &DAT_006de560;
  if (iVar1 == 0) {
    pcVar3 = (char *)FUN_004705f2(0x1f,0xffffffff);
    iVar1 = _strcmp(pcVar3,pcVar2);
    if (iVar1 == 0) {
      FUN_0040b84f();
      iVar1 = ((undefined4 *)*param_1)[0x18];
      FUN_00587bed(*(undefined4 *)*param_1,
                   CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(iVar1 + 0x26)));
    }
    pcVar3 = &DAT_006de560;
    pcVar2 = (char *)FUN_004705f2(0x23,0xffffffff);
    iVar1 = _strcmp(pcVar2,pcVar3);
    if (iVar1 == 0) {
      FUN_0040c04d();
LAB_00409499:
      iVar1 = ((undefined4 *)*param_1)[0x18];
      FUN_00587bed(*(undefined4 *)*param_1,
                   CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(iVar1 + 0x26)));
    }
  }
  else {
    pcVar3 = (char *)FUN_004705f2(0x1f,0xffffffff);
    iVar1 = _strcmp(pcVar3,pcVar2);
    if (iVar1 == 0) {
      FUN_005876ac(0x1f,s_ADDED_006c0f8c);
      FUN_0040c3d8();
      iVar1 = ((undefined4 *)*param_1)[0x18];
      FUN_00587bed(*(undefined4 *)*param_1,
                   CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(iVar1 + 0x26)));
    }
    pcVar3 = &DAT_006de560;
    pcVar2 = (char *)FUN_004705f2(0x23,0xffffffff);
    iVar1 = _strcmp(pcVar2,pcVar3);
    if (iVar1 == 0) {
      FUN_005876ac(0x23,s_ADDED_006c0f8c);
      goto LAB_00409499;
    }
  }
  pcVar3 = &DAT_006de560;
  pcVar2 = (char *)FUN_004705f2(0x22,0xffffffff);
  iVar1 = _strcmp(pcVar2,pcVar3);
  if (iVar1 == 0) {
    FUN_0040c8b7();
    iVar1 = ((undefined4 *)*param_1)[0x18];
    FUN_00587bed(*(undefined4 *)*param_1,
                 CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(iVar1 + 0x26)));
  }
LAB_004094e1:
  FUN_00470636(param_1[2]);
  return 1;
}

