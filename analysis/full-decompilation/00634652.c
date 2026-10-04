
int __thiscall FUN_00634652(int *param_1,int param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_10;
  int local_c;
  int local_8;
  
  iVar4 = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  iVar2 = FUN_006327fb(0);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = FUN_006340b6();
  if (0 < param_3) {
    do {
      if (iVar2 == -1) {
        puVar1 = (uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1);
        *puVar1 = *puVar1 | 1;
        break;
      }
      if (((iVar4 != 0) && (local_8 != 1)) || ((iVar2 != 0x2d && (iVar2 != 0x2b)))) {
        if (iVar2 == 0x2e) {
          if ((local_8 == 0) && (local_c == 0)) {
            local_c = 1;
          }
          else {
LAB_006346d7:
            iVar3 = FUN_006368c3(iVar2);
            if (iVar3 == 0) break;
            if (local_8 == 0) {
              local_10 = local_10 + 1;
            }
            else {
              local_8 = local_8 + 1;
            }
          }
        }
        else {
          if (((iVar2 != 0x45) && (iVar2 != 0x65)) || (local_8 != 0)) goto LAB_006346d7;
          local_c = local_c + 1;
          local_8 = 1;
        }
      }
      *(char *)(iVar4 + param_2) = (char)iVar2;
      iVar2 = FUN_00633ffa();
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_3);
    if (local_8 == 1) {
      iVar2 = FUN_005c4410(*(undefined1 *)(iVar4 + param_2));
      if (iVar2 == -1) {
        puVar1 = (uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1);
        *puVar1 = *puVar1 | 2;
      }
      else {
        iVar4 = iVar4 + -1;
        puVar1 = (uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1);
        *puVar1 = *puVar1 & 0xfffffffe;
      }
    }
    if ((local_10 != 0) && (iVar4 != param_3)) goto LAB_00634774;
  }
  puVar1 = (uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1);
  *puVar1 = *puVar1 | 2;
LAB_00634774:
  *(undefined1 *)(iVar4 + param_2) = 0;
  FUN_00632716();
  return iVar4;
}

