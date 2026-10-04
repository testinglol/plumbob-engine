
void __thiscall FUN_004a798b(int *param_1,int param_2,int param_3,char param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_c;
  int local_8;
  
  iVar2 = DAT_006f0084;
  iVar1 = DAT_006f0080;
  iVar4 = ((param_1[0xc] - param_1[10]) / 2 - param_2) + DAT_006f0080;
  iVar3 = ((param_1[0xd] - param_1[0xb]) / 2 - param_3) + DAT_006f0084;
  FUN_004aa1b9(&param_2,&param_3,&local_8,&local_c);
  iVar5 = param_2;
  if ((param_2 <= iVar4) && (iVar5 = iVar4, param_3 < iVar4)) {
    iVar5 = param_3;
  }
  if ((local_8 <= iVar3) && (local_8 = iVar3, local_c < iVar3)) {
    local_8 = local_c;
  }
  if (param_4 == '\0') {
    param_1[0x5c] = 0;
    param_1[0x5d] = 0;
    FUN_004a83dc(iVar5,local_8,1);
    (**(code **)(*param_1 + 0x48))();
  }
  else if (param_1[0x69] == 0) {
    FUN_004924ae(1);
    FUN_004c9d77(DAT_006c7778);
    FUN_004c9b93(iVar1,iVar5,iVar2,local_8,1);
    *(undefined1 *)((int)param_1 + 0x17a) = 1;
    FUN_004b050c();
  }
  return;
}

