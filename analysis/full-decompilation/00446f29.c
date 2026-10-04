
void __thiscall FUN_00446f29(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int local_20;
  int local_14;
  int *local_10;
  int local_c;
  undefined1 local_8;
  
  if ((((param_2 != (int *)0x0) &&
       (local_8 = (param_2[0x45] & 2U) != 0, (*(ushort *)(DAT_006e486c + 0x66) & 0x40) != 0)) &&
      (param_2 != (int *)0x0)) && (!(bool)local_8)) {
    local_c = (int)*(short *)((int)param_2 + 0x62e);
    if (local_c < 10) {
      if ((param_2[0x4d] - param_2[0x4c]) / 0x24 + -1 < 2) {
        local_20 = 0;
      }
      else {
        local_20 = param_2[0x4c] + 0x48;
      }
      if ((((local_20 != 0) && ((*(uint *)(local_20 + 0x1c) & 2) != 0)) &&
          (*(short *)(local_20 + 0x10) != 0)) &&
         ((piVar3 = (int *)FUN_00407498((int)*(short *)(local_20 + 0x10)), piVar3 != (int *)0x0 &&
          (iVar2 = FUN_0045741b(), iVar2 == 0xbaa71c5)))) {
        (**(code **)(*piVar3 + 0x50))(1);
        FUN_0044822b(piVar3);
      }
    }
    else {
      local_10 = (int *)0x0;
      if ((*(int *)(param_1 + 0xdc) != *(int *)(param_1 + 0xe0)) ||
         (FUN_00446396(), *(int *)(param_1 + 0xdc) != *(int *)(param_1 + 0xe0))) {
        local_10 = *(int **)(*(int *)(param_1 + 0xe0) + -4);
        *(int *)(param_1 + 0xe0) = *(int *)(param_1 + 0xe0) + -4;
        if ((local_10 != (int *)0x0) && (cVar1 = FUN_00422665(param_2 + 0x3d), cVar1 == '\0')) {
          if ((param_2[0x4d] - param_2[0x4c]) / 0x24 + -1 < 2) {
            local_14 = 0;
          }
          else {
            local_14 = param_2[0x4c] + 0x48;
          }
          if ((*(uint *)(local_14 + 0x1c) & 2) != 0) {
            if ((*(short *)(local_14 + 0x10) != 0) &&
               (iVar2 = FUN_00407498((int)*(short *)(local_14 + 0x10)), iVar2 != 0)) {
              FUN_0044822b(iVar2);
            }
            (**(code **)(*local_10 + 0x58))(param_2 + 0x3d,param_2[0x44],param_2,1,1);
            piVar3 = (int *)(**(code **)(*local_10 + 0x2c))();
            piVar4 = (int *)(**(code **)(*param_2 + 0x8c))();
            uVar5 = (**(code **)(*piVar4 + 0xb0))();
            (**(code **)(*piVar3 + 0xb8))(uVar5);
            (**(code **)(*piVar3 + 100))(1);
            (**(code **)(*piVar3 + 0xd4))(1);
            piVar4 = (int *)(**(code **)(*param_2 + 0x2c))(0);
            (**(code **)(*piVar4 + 0x54))();
            (**(code **)(*piVar3 + 0x50))(0);
            FUN_0044845a(&local_10);
          }
        }
      }
    }
  }
  return;
}

