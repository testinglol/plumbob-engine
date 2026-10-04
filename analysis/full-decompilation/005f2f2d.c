
void __thiscall FUN_005f2f2d(int param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_c;
  
  iVar4 = *(int *)(param_1 + 0xd4);
  if (param_2 != 0) {
    if (param_2 < 0) {
      for (; 1 < iVar4; iVar4 = iVar4 + -1) {
        iVar3 = FUN_005f2b22(iVar4,0xffffffff);
        cVar1 = *(char *)(*(int *)(param_1 + 0xe4) + iVar3 + iVar4);
        if ((cVar1 != ' ') && (cVar1 != '\n')) break;
      }
      cVar1 = *(char *)(*(int *)(param_1 + 0xe4) + iVar4);
      if (((0 < iVar4) && (cVar1 == ' ')) || (cVar1 == '\n')) {
        iVar4 = iVar4 + -1;
      }
    }
    bVar2 = false;
    local_c = 0;
    iVar3 = FUN_00636bef(param_2);
    if (0 < iVar3) {
      do {
        if (iVar4 < 0) goto LAB_005f302a;
        if ((*(int *)(param_1 + 0xe8) - *(int *)(param_1 + 0xe4)) + -1 < iVar4) break;
        iVar3 = *(int *)(param_1 + 0xe4);
        cVar1 = *(char *)(iVar3 + iVar4);
        iVar3 = (**(code **)(**(int **)(param_1 + 0x114) + 0x44))(iVar3 + iVar4,0xffffffff);
        if ((cVar1 == ' ') || (cVar1 == '\n')) {
          bVar2 = true;
          iVar4 = iVar4 + 1;
        }
        else {
          if (iVar3 < 2) {
            if (bVar2) {
              local_c = local_c + 1;
              goto LAB_005f3014;
            }
            bVar2 = false;
          }
          else {
            local_c = local_c + -1 + iVar3;
          }
          if (param_2 < 1) {
            uVar5 = 0xffffffff;
          }
          else {
            uVar5 = 1;
          }
          iVar3 = FUN_005f2b22(iVar4,uVar5);
          iVar4 = iVar4 + iVar3;
        }
LAB_005f3014:
        iVar3 = FUN_00636bef(param_2);
      } while (local_c < iVar3);
    }
  }
  if (iVar4 < 0) {
LAB_005f302a:
    iVar4 = 0;
  }
  else if ((*(int *)(param_1 + 0xe8) - *(int *)(param_1 + 0xe4)) + -1 < iVar4) {
    iVar4 = (*(int *)(param_1 + 0xe8) - *(int *)(param_1 + 0xe4)) + -1;
  }
  FUN_005f2c6c(iVar4 - *(int *)(param_1 + 0xd4),param_3,0);
  return;
}

