
void __thiscall FUN_00528f9f(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  undefined4 local_14;
  char local_10;
  char local_f;
  char local_e;
  int local_c;
  int local_8;
  
  bVar5 = param_1[0x65] != param_2;
  if (bVar5) {
    param_1[0x65] = param_2;
  }
  piVar1 = param_1 + 0x66;
  bVar6 = *piVar1 != param_3;
  if (bVar6) {
    *piVar1 = param_3;
  }
  bVar4 = bVar6 || bVar5;
  if (bVar6 || bVar5) {
    FUN_0050c966();
  }
  iVar2 = *piVar1;
  if (((iVar2 != -1) && (iVar3 = param_1[0x65], iVar2 != iVar3)) && (iVar3 != -1)) {
    FUN_004ea17e(iVar2,iVar3,&local_14);
    iVar2 = param_1[0x67];
    param_1[0x67] = local_c;
    if (((iVar2 != local_c) && (bVar4 = true, param_1 == *(int **)(param_1[0x6b] + 0x14))) &&
       (param_1[0x38] != 0)) {
      FUN_00528ce1();
    }
    iVar2 = param_1[0x68];
    param_1[0x68] = local_8;
    if (((iVar2 != local_8) && (bVar4 = true, param_1 == *(int **)(param_1[0x6b] + 0x14))) &&
       (param_1[0x38] != 0)) {
      FUN_00528ce1();
    }
    if (*(char *)((int)param_1 + 0x1a5) != local_10) {
      *(char *)((int)param_1 + 0x1a5) = local_10;
      bVar4 = true;
    }
    if (*(char *)((int)param_1 + 0x1a6) != local_e) {
      *(char *)((int)param_1 + 0x1a6) = local_e;
      bVar4 = true;
    }
    if ((char)param_1[0x69] != local_f) {
      *(char *)(param_1 + 0x69) = local_f;
      bVar4 = true;
    }
    if (param_1[0x6a] != 0) {
      FUN_0050c6f7(local_14);
    }
    if (bVar4) {
      (**(code **)(*param_1 + 0x168))();
    }
  }
  return;
}

