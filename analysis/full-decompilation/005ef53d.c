
uint __thiscall FUN_005ef53d(int param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int *_Buf1;
  
  piVar1 = *(int **)(param_1 + 0xc0);
  piVar2 = (int *)*piVar1;
  _Buf1 = param_3;
  if (piVar2 != piVar1) {
    do {
      _Buf1 = piVar2 + 2;
      piVar1 = (int *)_memcmp(_Buf1,param_3,0x10);
      if (piVar1 == (int *)0x0) break;
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)*(int *)(param_1 + 0xc0));
  }
  if (piVar2 != *(int **)(param_1 + 0xc0)) {
    param_3 = (int *)0x0;
    piVar1 = (int *)0x0;
    if ((_Buf1[0xc] - _Buf1[0xb]) / 0xc != 0) {
      piVar2 = (int *)_Buf1[0xb];
      do {
        if (((*piVar2 == *param_2) && (piVar2[1] == param_2[1])) && (piVar2[2] == param_2[2])) {
          return CONCAT31((int3)((uint)piVar2[2] >> 8),1);
        }
        param_3 = (int *)((int)param_3 + 1);
        piVar2 = piVar2 + 3;
        piVar1 = (int *)((_Buf1[0xc] - _Buf1[0xb]) / 0xc);
      } while (param_3 < piVar1);
    }
  }
  return (uint)piVar1 & 0xffffff00;
}

