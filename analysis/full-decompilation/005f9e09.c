
undefined4 __thiscall FUN_005f9e09(int *param_1,char param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined1 local_14 [4];
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  cVar1 = (**(code **)(*DAT_006fed70 + 8))();
  if (cVar1 == '\0') {
LAB_005f9fd8:
    uVar5 = 1;
  }
  else {
    if ((param_2 == '\0') || (cVar1 = (**(code **)(*param_1 + 0xf4))(1), cVar1 != '\0')) {
      *(undefined1 *)(param_1 + 0xb) = 0;
      *(undefined4 *)(param_1[0x2f] + 0x1c) = 0;
      *(undefined4 *)(param_1[0x2f] + 0x20) = 0;
      *(undefined4 *)(param_1[0x2f] + 0x30) = 1;
      iVar2 = (**(code **)(*(int *)param_1[0x20] + 0x2c))
                        ((int *)param_1[0x20],0,*(undefined4 *)(param_1[0x2f] + 4),&local_c,&local_8
                         ,&local_10,local_14,0);
      if (iVar2 == 0) {
        if (local_8 != 0) {
          uVar3 = (**(code **)(**(int **)param_1[0x2f] + 0x10))(local_c,local_8);
          if (uVar3 == 0) {
            (**(code **)(*(int *)param_1[0x20] + 0x4c))
                      ((int *)param_1[0x20],local_c,local_8,local_10,0);
            goto LAB_005f9e91;
          }
          if (uVar3 < local_8) {
            iVar2 = local_c;
            if ((char)param_1[9] == '\0') {
              *(undefined4 *)(param_1[0x2f] + 0x30) = 0;
              *(undefined4 *)(param_1[0x2f] + 0x1c) = 1;
              *(uint *)(param_1[0x2f] + 0x20) = uVar3 / *(uint *)(param_1[0x2f] + 8);
              _memset((void *)(uVar3 + local_c),
                      (-(uint)(*(short *)((int)param_1 + 0xb6) != 8) & 0xffffff80) + 0x80,
                      local_8 - uVar3);
            }
            else {
              do {
                local_8 = local_8 - uVar3;
                iVar2 = iVar2 + uVar3;
                (**(code **)(**(int **)param_1[0x2f] + 0x14))();
                uVar3 = (**(code **)(**(int **)param_1[0x2f] + 0x10))(iVar2,local_8);
              } while (uVar3 < local_8);
            }
          }
          FUN_005f7a3c(local_c,local_8);
        }
        iVar2 = (**(code **)(*(int *)param_1[0x20] + 0x4c))
                          ((int *)param_1[0x20],local_c,local_8,local_10,0);
        puVar4 = (undefined4 *)param_1[0x2f];
        if (iVar2 == 0) {
          puVar4[5] = 0;
          *(undefined4 *)(param_1[0x2f] + 0x10) = 0;
          *(undefined4 *)(param_1[0x2f] + 0xc) = 0;
          *(undefined4 *)(param_1[0x2f] + 0x18) = 0;
          *(undefined1 *)(param_1 + 0x30) = 1;
          goto LAB_005f9fd8;
        }
      }
      else {
LAB_005f9e91:
        puVar4 = (undefined4 *)param_1[0x2f];
      }
      (**(code **)(*(int *)*puVar4 + 8))();
      FUN_006321f0(*(undefined4 *)param_1[0x2f]);
      *(undefined4 *)param_1[0x2f] = 0;
    }
    uVar5 = 0;
  }
  return uVar5;
}

