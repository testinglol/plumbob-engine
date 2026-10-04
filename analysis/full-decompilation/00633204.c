
int * __thiscall FUN_00633204(int *param_1,undefined4 param_2)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = FUN_006322ac();
  if (iVar2 != 0) {
    if (*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 0x30) == 0) {
      iVar2 = FUN_0063268c((undefined1)param_2);
      if (iVar2 == -1) {
        iVar2 = (**(code **)(**(int **)(*(int *)(*param_1 + 4) + 4 + (int)param_1) + 0x1c))
                          ((undefined1)param_2);
        if (iVar2 == -1) {
          puVar1 = (uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1);
          *puVar1 = *puVar1 | 6;
        }
      }
    }
    else {
      param_2._3_1_ = 0;
      param_2._2_1_ = (undefined1)param_2;
      FUN_00632520(&DAT_006de560,(int)&param_2 + 2);
    }
    FUN_00632320();
  }
  return param_1;
}

