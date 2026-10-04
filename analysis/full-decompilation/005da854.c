
undefined1 __thiscall FUN_005da854(int param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  char cVar3;
  undefined1 uVar4;
  int *piVar6;
  uint *local_10;
  int *local_c;
  undefined1 local_5;
  undefined4 *puVar5;
  
  puVar2 = param_2;
  if (DAT_006d6f9c == '\0') {
    return 0;
  }
  local_5 = 0;
  local_c = (int *)*param_2;
  if ((local_c < (int *)0x4) || ((int *)0x6 < local_c)) {
    if (local_c < (int *)0x7) {
      return 0;
    }
    if ((int *)0xf < local_c) {
      return 0;
    }
    if ((local_c == (int *)0x7) &&
       (((*(int *)(param_1 + 0x18c) == 0 || (*(int **)(param_1 + 0x174) == (int *)0x0)) ||
        (cVar3 = (**(code **)(**(int **)(param_1 + 0x174) + 0x8c))(0x1000), cVar3 == '\0')))) {
      FUN_005d9dba();
    }
    piVar6 = *(int **)(param_1 + 0x20);
    if (piVar6 == (int *)0x0) {
      if (*(int *)(param_1 + 0x28) != 0) {
        param_2 = (uint *)((uint)param_2 & 0xffffff);
        piVar6 = (int *)(*(int *)(param_1 + 0x2c) + 0x38);
        puVar1 = (uint *)*piVar6;
        local_10 = (uint *)*puVar1;
        if (local_10 != puVar1) {
          do {
            local_c = (int *)local_10[2];
            cVar3 = (**(code **)(*local_c + 0x8c))(0x10000);
            if (((cVar3 != '\0') && (cVar3 = (**(code **)(*local_c + 0x8c))(1), cVar3 != '\0')) &&
               (cVar3 = (**(code **)(*local_c + 0x8c))(2), cVar3 != '\0')) {
              cVar3 = (**(code **)(*local_c + 0x70))(puVar2[1],puVar2[2]);
              param_2 = (uint *)CONCAT13(cVar3,param_2._0_3_);
              if (cVar3 != '\0') {
                local_5 = FUN_005dcbd1(puVar2);
                break;
              }
            }
            local_10 = (uint *)*local_10;
          } while (local_10 != (uint *)*piVar6);
          if (param_2._3_1_ != '\0') {
            return local_5;
          }
        }
        cVar3 = (**(code **)(**(int **)(param_1 + 0x28) + 0x70))(puVar2[1],puVar2[2]);
        if (cVar3 == '\0') {
          return local_5;
        }
        cVar3 = (**(code **)(**(int **)(param_1 + 0x28) + 0x8c))(2);
        if (cVar3 == '\0') {
          return local_5;
        }
        cVar3 = (**(code **)(**(int **)(param_1 + 0x28) + 0x8c))(1);
        if (cVar3 == '\0') {
          return local_5;
        }
      }
      uVar4 = FUN_005dcbd1(puVar2);
      return uVar4;
    }
    param_2 = (uint *)0x0;
    local_10 = (uint *)0x0;
    FUN_00436feb(&param_2,&local_10);
    puVar2[1] = puVar2[1] - (int)param_2;
    puVar2[2] = puVar2[2] - (int)local_10;
    if (local_c == (int *)0xd) {
      FUN_005ddddb();
    }
    else if (local_c == (int *)0xf) {
      FUN_005e749a(0);
      FUN_005e73da();
      FUN_005e743b();
    }
    else if ((local_c == (int *)0x7) || (local_c == (int *)0x8)) {
      (**(code **)(*piVar6 + 0x44))();
      FUN_00436e16();
    }
    puVar5 = (undefined4 *)*piVar6;
  }
  else {
    if (*(int **)(param_1 + 0x24) == (int *)0x0) {
      return 0;
    }
    puVar5 = (undefined4 *)**(int **)(param_1 + 0x24);
  }
  uVar4 = (*(code *)*puVar5)(puVar2);
  return uVar4;
}

