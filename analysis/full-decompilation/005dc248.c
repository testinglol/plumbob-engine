
char __thiscall FUN_005dc248(int *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *extraout_ECX;
  int **extraout_ECX_00;
  int *extraout_ECX_01;
  int **ppiStack_2c;
  int *piStack_28;
  int *piStack_24;
  int *piStack_20;
  undefined4 local_10;
  int *local_c;
  char local_5;
  
  local_5 = '\0';
  if (param_2 != (int *)0x0) {
    piStack_24 = (int *)0x5dc268;
    piStack_20 = param_1;
    (**(code **)(*param_2 + 0x1c))();
    piStack_24 = (int *)0x5dc270;
    local_5 = (**(code **)(*param_2 + 0xc))();
    if (local_5 == '\0') {
      piStack_24 = (int *)0x0;
      piStack_28 = (int *)0x5dc35a;
      (**(code **)(*param_2 + 0x1c))();
    }
    else {
      if ((char)param_1[0xf] == '\0') {
        *(undefined1 *)(param_1 + 0xf) = 1;
      }
      iVar3 = param_1[0xe];
      piStack_24 = (int *)&param_2;
      ppiStack_2c = &piStack_28;
      piStack_28 = extraout_ECX;
      FUN_00575825();
      ppiStack_2c = extraout_ECX_00;
      FUN_00602902(&ppiStack_2c);
      piVar2 = (int *)FUN_00602c63(&local_c);
      if (*piVar2 == iVar3) {
        piStack_28 = (int *)param_1[0xe];
        local_c = (int *)*piStack_28;
        if (local_c != piStack_28) {
          do {
            piStack_24 = (int *)0x10000;
            piStack_28 = (int *)0x5dc2ce;
            cVar1 = (**(code **)(*(int *)local_c[2] + 0x8c))();
            piStack_28 = extraout_ECX_01;
            if (cVar1 == '\0') break;
            local_c = (int *)*local_c;
          } while (local_c != (int *)param_1[0xe]);
        }
        piStack_24 = (int *)&param_2;
        ppiStack_2c = &local_c;
        FUN_00602c56();
        ppiStack_2c = (int **)&local_10;
        FUN_0057be12();
      }
      *(undefined1 *)(param_1 + 0xf) = 0;
      piStack_24 = (int *)0x5dc308;
      piVar2 = (int *)FUN_005d0a09();
      if (piVar2 == param_1) {
        piStack_24 = (int *)0x5dc313;
        iVar3 = FUN_0060783f();
        if (iVar3 == 1) {
          piStack_24 = param_2;
          piStack_28 = (int *)0x5dc326;
          FUN_005d9884();
        }
      }
      piStack_24 = (int *)0x5dc331;
      (**(code **)(*param_2 + 0x88))();
      piStack_24 = (int *)0x4000;
      piStack_28 = (int *)0x5dc340;
      cVar1 = (**(code **)(*param_1 + 0x8c))();
      if (cVar1 != '\0') {
        piStack_28 = (int *)0x1;
        ppiStack_2c = (int **)0x5dc34e;
        FUN_005ddfdc();
      }
    }
  }
  return local_5;
}

