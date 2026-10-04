
undefined4 __thiscall FUN_005dc47e(int *param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *extraout_ECX;
  undefined4 *puVar4;
  int *local_c;
  int *local_8;
  
  if (((param_2 != (int *)0x0) &&
      (local_c = param_1, local_8 = param_1, cVar1 = FUN_005da398(param_2), cVar1 != '\0')) &&
     (cVar1 = (**(code **)(*param_2 + 0x8c))(0x10), cVar1 != '\0')) {
    iVar2 = (**(code **)(*param_1 + 0x18))();
    if (iVar2 != 0) {
      piVar3 = (int *)(**(code **)(*param_1 + 0x18))();
      (**(code **)(*piVar3 + 0x4c))(param_1);
    }
    cVar1 = (**(code **)(*param_2 + 0x8c))(0x10);
    if (cVar1 != '\0') {
      if ((char)param_1[0xf] == '\0') {
        *(undefined1 *)(param_1 + 0xf) = 1;
      }
      FUN_005de7e8(&param_2);
      piVar3 = (int *)param_1[0xe];
      local_8 = (int *)*piVar3;
      if (local_8 != piVar3) {
        do {
          cVar1 = (**(code **)(*(int *)local_8[2] + 0x8c))(0x10000);
          piVar3 = extraout_ECX;
          if (cVar1 == '\0') break;
          local_8 = (int *)*local_8;
        } while (local_8 != (int *)param_1[0xe]);
      }
      puVar4 = &param_2;
      FUN_00602c56(&local_8);
      FUN_0057be12(&local_c,piVar3,puVar4);
      *(undefined1 *)(param_1 + 0xf) = 0;
      return 1;
    }
  }
  return 0;
}

