#ifndef __SimpleArborClusterizer_H__
#define __SimpleArborClusterizer_H__

#include "RecoParticleFlow/PFClusterProducer/interface/InitialClusteringStepBase.h"
#include "DataFormats/ParticleFlowReco/interface/PFRecHitFraction.h"

class SimpleArborClusterizer : public InitialClusteringStepBase {
  typedef SimpleArborClusterizer B2DGT;
 public:
  SimpleArborClusterizer(const edm::ParameterSet& conf) :
    InitialClusteringStepBase(conf),
      _cellSize(conf.getParameter<double>("cellSize")),
      _layerThickness(conf.getParameter<double>("layerThickness")) { }
  virtual ~SimpleArborClusterizer() {}
  SimpleArborClusterizer(const B2DGT&) = delete;
  B2DGT& operator=(const B2DGT&) = delete;

  void buildClusters(const edm::Handle<reco::PFRecHitCollection>&,
		     const std::vector<bool>&,
		     const std::vector<bool>&, 
		     reco::PFClusterCollection&);
  
 private:  
  double _cellSize,_layerThickness;
};

DEFINE_EDM_PLUGIN(InitialClusteringStepFactory,
		  SimpleArborClusterizer,
		  "SimpleArborClusterizer");

#endif
