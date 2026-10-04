
void __fastcall FUN_004e6646(int param_1)

{
  int iVar1;
  char cVar2;
  char cStack00000007;
  undefined4 local_8;
  
  local_8 = 5;
  FUN_00464973(&local_8,1);
  cStack00000007 = *(char *)(param_1 + 0x20) == '\0';
  cVar2 = '\x01';
  if (!(bool)cStack00000007) {
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  FUN_00464895(&stack0x00000007,1);
  *(bool *)param_1 = cStack00000007 != '\0';
  cStack00000007 = DAT_006f0139;
  FUN_00464895(&stack0x00000007,1);
  FUN_004e60c8(cStack00000007 != '\0');
  FUN_004e60c8(1);
  cStack00000007 = DAT_006f0138;
  FUN_00464895(&stack0x00000007,1);
  DAT_006f0138 = cStack00000007 != '\0';
  if (*(int **)(DAT_006e486c + 4) != (int *)0x0) {
    (**(code **)(**(int **)(DAT_006e486c + 4) + 0x48))();
  }
  cStack00000007 = DAT_006f013a;
  FUN_00464895(&stack0x00000007,1);
  DAT_006f013a = cStack00000007 != '\0';
  if (*(int **)(DAT_006e486c + 4) != (int *)0x0) {
    (**(code **)(**(int **)(DAT_006e486c + 4) + 0x48))();
  }
  cStack00000007 = FUN_004e6141();
  FUN_00464895(&stack0x00000007,1);
  FUN_004e6166((int)cStack00000007);
  iVar1 = FUN_005d14f7();
  if (iVar1 != 0) {
    if (iVar1 == 1) goto LAB_004e675e;
    if (iVar1 == 2) {
      cVar2 = '\x02';
      goto LAB_004e675e;
    }
  }
  cVar2 = '\0';
LAB_004e675e:
  cStack00000007 = cVar2;
  FUN_00464895(&stack0x00000007,1);
  FUN_004e61c6((int)cStack00000007);
  cStack00000007 = FUN_004e62a7();
  FUN_00464895(&stack0x00000007,1);
  *(int *)(param_1 + 0x14) = (int)cStack00000007;
  if (*(int *)(DAT_006e486c + 0x10) != 0) {
    FUN_0057afae((int)cStack00000007);
  }
  cStack00000007 = FUN_004e62e0();
  FUN_00464895(&stack0x00000007,1);
  *(int *)(param_1 + 0x18) = (int)cStack00000007;
  if (*(int *)(DAT_006e486c + 0x10) != 0) {
    FUN_0057b015((int)cStack00000007);
  }
  cStack00000007 = FUN_004e6319();
  FUN_00464895(&stack0x00000007,1);
  *(int *)(param_1 + 0x1c) = (int)cStack00000007;
  if (*(int *)(DAT_006e486c + 0x10) != 0) {
    FUN_0057b07c((int)cStack00000007);
  }
  cStack00000007 = DAT_006c2971;
  FUN_00464895(&stack0x00000007,1);
  DAT_006c2971 = cStack00000007 != '\0';
  cStack00000007 = DAT_006c2970;
  FUN_00464895(&stack0x00000007,1);
  FUN_004322cf(cStack00000007 != '\0');
  cStack00000007 = *(char *)(param_1 + 0xc);
  FUN_00464895(&stack0x00000007,1);
  FUN_004e6387(cStack00000007 != '\0');
  cStack00000007 = DAT_006c9f91 == '\0';
  FUN_00464895(&stack0x00000007,1);
  DAT_006c9f91 = cStack00000007 == '\0';
  cStack00000007 = *(char *)(param_1 + 1);
  FUN_00464895(&stack0x00000007,1);
  *(bool *)(param_1 + 1) = cStack00000007 != '\0';
  if ((short)local_8 < 2) {
    *(undefined4 *)(param_1 + 8) = 0;
  }
  else {
    FUN_00464a5e(param_1 + 8,1);
  }
  if ((short)local_8 < 3) {
    *(undefined1 *)(param_1 + 2) = 1;
    *(undefined1 *)(param_1 + 3) = 1;
    *(undefined1 *)(param_1 + 4) = 1;
  }
  else {
    cStack00000007 = FUN_004e63de();
    FUN_00464895(&stack0x00000007,1);
    *(bool *)(param_1 + 2) = cStack00000007 != '\0';
    if (cStack00000007 != '\0') {
      DAT_006d7444 = 0;
      DAT_006d74f0 = 0xfa;
    }
    else {
      DAT_006d7444 = 0x2ee;
      DAT_006d74f0 = 0x14d;
    }
    cStack00000007 = *(char *)(param_1 + 3);
    FUN_00464895(&stack0x00000007,1);
    *(bool *)(param_1 + 3) = cStack00000007 != '\0';
    cStack00000007 = *(char *)(param_1 + 4);
    FUN_00464895(&stack0x00000007,1);
    *(bool *)(param_1 + 4) = cStack00000007 != '\0';
  }
  if ((short)local_8 < 4) {
    *(undefined1 *)(param_1 + 5) = 1;
  }
  else {
    cStack00000007 = *(char *)(param_1 + 5);
    FUN_00464895(&stack0x00000007,1);
    *(bool *)(param_1 + 5) = cStack00000007 != '\0';
  }
  if ((short)local_8 < 5) {
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  else {
    FUN_00464a5e(param_1 + 0x10,1);
  }
  return;
}

