
int __thiscall FUN_005f7b85(int param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  int local_18;
  int *local_14;
  undefined2 *local_10;
  int local_c;
  int local_8;
  
  iVar3 = *(int *)(param_1 + 0x4a4c);
  if (-1 < iVar3) {
    if (iVar3 == 0) {
      return 0;
    }
    if (iVar3 < param_3) {
      param_3 = iVar3;
    }
  }
  local_c = 0;
  iVar3 = 0;
  if (0 < param_3) {
    do {
      if (*(int *)(param_1 + 0x4a50) == 0) {
        if (*(int *)(param_1 + 0x4a48) == 0) {
          return local_c;
        }
        if (*(char *)(param_1 + 0x4a5c) == '\0') {
          *(undefined4 *)(param_1 + 0x24ac) = 0;
          *(undefined4 *)(param_1 + 0x24a4) = *(undefined4 *)(param_1 + 0x4a44);
        }
        else {
          FUN_0062c122(*(undefined4 *)(param_1 + 0x4a44),0);
          uVar1 = *(undefined4 *)(&DAT_00675ef4 + (uint)*(byte *)(param_1 + 0x2490) * 4);
          *(undefined1 *)(param_1 + 0x4a5c) = 0;
          *(undefined4 *)(param_1 + 0x4a58) = uVar1;
        }
        iVar3 = FUN_0062c026((void *)(param_1 + 0x1244));
        if (iVar3 < 0) {
          _memset((void *)(param_1 + 0x1244),0,*(size_t *)(param_1 + 0x248c));
        }
        iVar3 = *(int *)(param_1 + 0x2498) + 4;
        *(undefined4 *)(param_1 + 0x4a54) = 0;
        *(int *)(param_1 + 0x4a44) = *(int *)(param_1 + 0x4a44) + iVar3;
        *(int *)(param_1 + 0x4a48) = *(int *)(param_1 + 0x4a48) - iVar3;
        *(int *)(param_1 + 0x4a50) = *(int *)(param_1 + 0x248c) / (*(int *)(param_1 + 0x4a40) << 1);
      }
      iVar3 = *(int *)(param_1 + 0x4a58);
      if (0 < iVar3) {
        iVar2 = *(int *)(param_1 + 0x4a50);
        if (iVar3 < iVar2) {
          *(int *)(param_1 + 0x4a54) = *(int *)(param_1 + 0x4a54) + iVar3;
          *(int *)(param_1 + 0x4a50) = iVar2 - iVar3;
          *(undefined4 *)(param_1 + 0x4a58) = 0;
        }
        else {
          *(undefined4 *)(param_1 + 0x4a50) = 0;
          *(int *)(param_1 + 0x4a58) = iVar3 - iVar2;
        }
      }
      iVar3 = *(int *)(param_1 + 0x4a50);
      if (0 < iVar3) {
        if (param_3 < iVar3) {
          iVar3 = param_3;
        }
        iVar2 = *(int *)(param_1 + 0x4a40);
        local_8 = 0;
        if (0 < iVar2) {
          local_14 = param_2;
          do {
            if (*local_14 != 0) {
              puVar4 = (undefined2 *)(*local_14 + local_c * 2);
              local_10 = (undefined2 *)
                         (param_1 + 0x1244 + (*(int *)(param_1 + 0x4a54) * iVar2 + local_8) * 2);
              local_18 = iVar3;
              if (0 < iVar3) {
                do {
                  *puVar4 = *local_10;
                  puVar4 = puVar4 + 1;
                  local_18 = local_18 + -1;
                  local_10 = local_10 + iVar2;
                } while (local_18 != 0);
              }
            }
            local_8 = local_8 + 1;
            local_14 = local_14 + 1;
          } while (local_8 < iVar2);
        }
        *(int *)(param_1 + 0x4a54) = *(int *)(param_1 + 0x4a54) + iVar3;
        *(int *)(param_1 + 0x4a50) = *(int *)(param_1 + 0x4a50) - iVar3;
        if (-1 < *(int *)(param_1 + 0x4a4c)) {
          *(int *)(param_1 + 0x4a4c) = *(int *)(param_1 + 0x4a4c) - iVar3;
        }
        local_c = local_c + iVar3;
      }
      iVar3 = local_c;
    } while (local_c < param_3);
  }
  return iVar3;
}

