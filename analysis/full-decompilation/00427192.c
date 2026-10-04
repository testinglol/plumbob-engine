
undefined4 __thiscall FUN_00427192(int param_1,short *param_2)

{
  undefined4 *puVar1;
  short *psVar2;
  short *psVar3;
  char cVar4;
  undefined4 *puVar5;
  
  psVar3 = param_2;
  if ((char)param_2[0x12] != '\0') {
    param_2 = (short *)0x0;
    puVar1 = *(undefined4 **)(param_1 + 0x14c);
    for (puVar5 = *(undefined4 **)(param_1 + 0x148); puVar5 != puVar1; puVar5 = puVar5 + 1) {
      psVar2 = (short *)*puVar5;
      if ((((psVar2 != (short *)0x0) && (psVar2 != psVar3)) &&
          (cVar4 = FUN_00423f63(), cVar4 != '\0')) &&
         ((psVar2[0x77] != 0 &&
          (cVar4 = FUN_0042720f(psVar2 + 6,(int)*psVar2,psVar3 + 6,(int)*psVar3), cVar4 != '\0'))))
      {
        param_2 = (short *)((int)param_2 + 1);
      }
    }
    *(short **)(psVar3 + 0x10) = param_2;
  }
  return *(undefined4 *)(psVar3 + 0x10);
}

