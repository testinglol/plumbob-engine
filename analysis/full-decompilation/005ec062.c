
undefined4 __thiscall
FUN_005ec062(int *param_1,int param_2,int param_3,undefined1 param_4,int param_5,int param_6,
            int param_7,int param_8,int param_9,undefined1 param_10)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((char)param_1[0x1d] == '\0') {
    if ((char)param_1[1] == '\0') {
      iVar2 = (**(code **)(*DAT_006fe8bc + 0x1c))();
      param_1[0x1e] = -(uint)(iVar2 != 0) & iVar2 - 0x48U;
      if ((param_2 != 0) && (param_3 != 0)) {
        if (DAT_006fe914 != '\0') {
          *(undefined1 *)(param_1 + 0x1f) = 0;
        }
        param_1[7] = param_2;
        param_1[5] = 0;
        param_1[6] = 0;
        param_1[8] = param_3;
        param_1[0x19] = 0;
        param_1[0x1a] = param_1[6];
        param_1[0x1b] = param_1[7];
        param_1[0x1c] = param_1[8];
        param_1[2] = param_5;
        param_1[3] = param_6;
        param_1[4] = param_7;
        *(undefined1 *)((int)param_1 + 0x7d) = param_4;
        param_1[0x20] = param_9;
        param_1[0x21] = param_8;
        *(undefined1 *)(param_1 + 0x24) = param_10;
        cVar1 = (**(code **)(*param_1 + 0x118))();
        if (cVar1 != '\0') {
          cVar1 = (**(code **)(*(int *)param_1[0x12] + 0x48))
                            (param_1 + 2,(int *)param_1[0x12] + 0x15);
          if (cVar1 != '\0') {
            *(undefined1 *)(param_1 + 1) = 1;
            *(undefined1 *)(param_1 + 0x1d) = 1;
            goto LAB_005ec137;
          }
        }
      }
    }
    uVar3 = 0;
  }
  else {
LAB_005ec137:
    uVar3 = 1;
  }
  return uVar3;
}

