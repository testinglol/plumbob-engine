
void __fastcall FUN_00512892(int *param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  char cVar4;
  undefined4 *puVar5;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (**(code **)(*param_1 + 0x168))();
  FUN_004df5cd(&local_c,&local_8);
  cVar4 = FUN_004e076c(param_1 + 0x53);
  if (cVar4 == '\0') {
    param_1[0x41] = param_1[0x43];
    local_10 = 0;
    puVar5 = (undefined4 *)(param_1[0x50] + param_1[0x44] * 0xc);
  }
  else {
    local_10 = param_1[0x56];
    puVar5 = (undefined4 *)(param_1[0x50] + param_1[0x44] * 0xc);
  }
  *puVar5 = local_8;
  puVar5[1] = local_c;
  puVar5[2] = local_10;
  param_1[0x44] = param_1[0x44] + 1;
  if ((uint)((param_1[0x51] - param_1[0x50]) / 0xc) <= (uint)param_1[0x44]) {
    param_1[0x44] = 0;
  }
  if (*(char *)((int)param_1 + 0x11a) != '\0') {
    iVar1 = ((int *)param_1[0x50])[1];
    iVar2 = *(int *)param_1[0x50];
    for (fVar3 = (float)(param_1[0x3f] - param_1[0x3d]) * (float)param_1[0x35];
        fVar3 < (float)(iVar1 + iVar2); fVar3 = (float)(param_1[0x3f] - param_1[0x3d]) * fVar3) {
      fVar3 = (float)param_1[0x35] + (float)param_1[0x35];
      param_1[0x35] = (int)fVar3;
    }
    *(undefined1 *)((int)param_1 + 0x11a) = 0;
  }
  *(undefined1 *)(param_1 + 0x46) = 1;
  return;
}

