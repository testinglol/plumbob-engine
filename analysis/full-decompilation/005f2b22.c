
int __thiscall FUN_005f2b22(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_10;
  
  if ((param_3 != 0) && (cVar1 = (**(code **)(**(int **)(param_1 + 0x114) + 0x48))(), cVar1 != '\0')
     ) {
    iVar2 = FUN_004096c2();
    iVar4 = *(int *)(param_1 + 0xe8);
    iVar5 = *(int *)(param_1 + 0xe4);
    iVar6 = 0;
    if (param_3 < 1) {
      if (param_3 < 0) {
        if (param_2 < 1) {
          param_3 = -1;
        }
        else {
          iVar6 = *(int *)(param_1 + 0xf0);
          iVar4 = FUN_005f4175(param_2);
          iVar6 = **(int **)(iVar6 + iVar4 * 4);
          if (iVar6 == param_2) {
            iVar6 = FUN_005f4175(param_2);
            iVar6 = **(int **)(*(int *)(param_1 + 0xf0) + (iVar6 + -1) * 4);
          }
          iVar4 = FUN_00636bef(param_3);
          param_3 = 0;
          for (; 0 < iVar4; iVar4 = iVar4 + -1) {
            while (iVar6 < param_2) {
              iVar5 = (**(code **)(**(int **)(param_1 + 0x114) + 0x44))(iVar2 + iVar6,0xffffffff);
              local_10 = iVar6 - (iVar6 + iVar5);
              iVar6 = iVar6 + iVar5;
            }
            iVar6 = *(int *)(param_1 + 0xf0);
            param_3 = param_3 + local_10;
            param_2 = param_2 + local_10;
            iVar5 = FUN_005f4175(param_2);
            iVar6 = **(int **)(iVar6 + iVar5 * 4);
            if (param_2 < 1) {
              return param_3 + -1;
            }
            if (iVar6 == param_2) {
              iVar6 = FUN_005f4175(param_2);
              iVar6 = **(int **)(*(int *)(param_1 + 0xf0) + (iVar6 + -1) * 4);
            }
          }
        }
      }
    }
    else {
      do {
        if (param_2 + iVar6 < iVar4 - iVar5) {
          iVar3 = (**(code **)(**(int **)(param_1 + 0x114) + 0x44))
                            (iVar2 + iVar6 + param_2,0xffffffff);
          iVar6 = iVar6 + -1 + iVar3;
          param_3 = param_3 + -1 + iVar3;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < param_3);
    }
  }
  return param_3;
}

