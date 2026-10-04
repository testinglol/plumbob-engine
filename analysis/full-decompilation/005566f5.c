
void FUN_005566f5(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined2 *puVar4;
  undefined4 local_c;
  int local_8;
  
  local_c = 0;
  if (param_1 != -1) {
    FUN_00425db3(param_1);
    iVar2 = FUN_004102e1();
    param_1 = 0;
    if (0 < iVar2) {
      do {
        puVar3 = (undefined4 *)FUN_004102ab(param_1);
        puVar4 = (undefined2 *)FUN_00425769(*puVar3);
        if (puVar4 != (undefined2 *)0x0) {
          FUN_0042a8e3(*puVar4);
          sVar1 = FUN_0041f662(7,0x99e81bec,&local_c);
          local_8 = (int)sVar1;
          if (param_2 < local_8) {
            local_8 = param_2;
          }
          FUN_0041f49d(7,0x99e81bec,local_8);
          param_2 = param_2 - local_8;
          FUN_0041f662(7,0x99e81bec,&local_c);
          if (param_2 == 0) {
            return;
          }
        }
        param_1 = param_1 + 1;
      } while (param_1 < iVar2);
    }
  }
  return;
}

