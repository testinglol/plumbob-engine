
void __thiscall FUN_005d31f5(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 == (undefined4 *)0x0) {
    if (*(char *)(param_1 + 0xc0) != '\0') {
      FUN_005c6150();
      *(undefined4 *)(param_1 + 0xf8) = *(undefined4 *)(param_1 + 0xa8);
      *(undefined4 *)(param_1 + 0xfc) = *(undefined4 *)(param_1 + 0xac);
      *(undefined4 *)(param_1 + 0x100) = *(undefined4 *)(param_1 + 0xb0);
      *(undefined4 *)(param_1 + 0x104) = *(undefined4 *)(param_1 + 0xb4);
      *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(param_1 + 0xb8);
      *(undefined4 *)(param_1 + 0x10c) = *(undefined4 *)(param_1 + 0xbc);
      *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffffffe;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0xf8) = *param_2;
    *(undefined4 *)(param_1 + 0xfc) = param_2[1];
    *(undefined4 *)(param_1 + 0x100) = param_2[2];
    FUN_00462be8(param_2 + 3);
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffffffe;
    *(undefined1 *)(param_1 + 0xc0) = 0;
  }
  *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) & 0xfffffffe;
  if ((*(uint *)(param_1 + 0xc4) & 4) != 0) {
    FUN_005d0fb5();
  }
  _memset(&local_14,0,0x10);
  uVar3 = 0;
  local_14 = 0x10;
  local_10 = 0x10800;
  local_c = 0x112;
  local_8 = 0;
  if (*(int *)(param_1 + 0xe4) - *(int *)(param_1 + 0xe0) >> 3 != 0) {
    piVar1 = (int *)(*(int *)(param_1 + 0xe0) + 4);
    do {
      if (local_8 < *piVar1 + 1U) {
        local_8 = *piVar1 + 1U;
      }
      uVar3 = uVar3 + 1;
      piVar1 = piVar1 + 2;
    } while (uVar3 < (uint)(*(int *)(param_1 + 0xe4) - *(int *)(param_1 + 0xe0) >> 3));
  }
  piVar1 = (int *)FUN_005d0135();
  iVar2 = (**(code **)(*piVar1 + 0x24))(piVar1,&local_14,(undefined4 *)(param_1 + 0x114),0,0);
  if (-1 < iVar2) {
    piVar1 = *(int **)(param_1 + 0x114);
    iVar2 = (**(code **)(*piVar1 + 0xc))(piVar1,0x21,&param_2,0);
    if (-1 < iVar2) {
      puVar4 = *(undefined4 **)(param_1 + 200);
      puVar5 = param_2;
      for (iVar2 = (local_8 & 0x7ffffff) << 3; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      }
      iVar2 = (**(code **)(**(int **)(param_1 + 0x114) + 0x10))(*(int **)(param_1 + 0x114));
      if (-1 < iVar2) {
        (**(code **)(**(int **)(param_1 + 0x114) + 0x1c))
                  (*(int **)(param_1 + 0x114),*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x38),0);
      }
    }
  }
  return;
}

